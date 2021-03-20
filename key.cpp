#include "key.h"

Key::Key(void)
{
  _regs_head = NULL;
  _regs_last = NULL;
}

TRegister *Key::searchRegister(uint8_t irrigador, uint8_t setor)
{
  TRegister *reg = _regs_head;
  if (reg == NULL)
  {
    return (NULL);
  }
  do
  {
    if ((reg->irrigador == irrigador) && (reg->setor == setor))
    {
      return (reg);
    }
    reg = reg->next;
  } while (reg != NULL);
  return (NULL);
}

TRegister *Key::firstRegister(void)
{
  if (_regs_head == NULL)
  {
    return (NULL);
  }
  else
  {
    return _regs_head;
  }
}

TRegister *Key::lastRegister(void)
{
  if (_regs_last == NULL)
  {
    return (NULL);
  }
  else
  {
    return _regs_last;
  }
}

void Key::addReg(uint8_t irrigador, uint8_t setor, bool estado, uint32_t timeIrrigationStart, uint32_t timeIrrigationFinish)
{
  TRegister *newreg;

  newreg = (TRegister *)malloc(sizeof(TRegister));
  newreg->irrigador = irrigador;
  newreg->setor = setor;
  newreg->estado = estado;
  newreg->connected = false;
  newreg->timeIrrigationStart = timeIrrigationStart;
  newreg->timeIrrigationFinish = timeIrrigationFinish;
  newreg->next = NULL;

  if (_regs_head == NULL)
  {
    _regs_head = newreg;
    _regs_last = newreg;
  }
  else
  {
    if ((_regs_head->irrigador == newreg->irrigador) &&
        (_regs_head->setor == newreg->setor))
    {
      _regs_head->timeIrrigationFinish = newreg->timeIrrigationFinish;
    }
    else
    {
      _regs_last->next = newreg;
      _regs_last = newreg;
    }
  }
}

void Key::reajustTime(uint8_t irrigador, uint8_t setor, uint32_t TSAtual)
{
  TRegister *reg = searchRegister(irrigador, setor);
  TRegister *regNext = reg->next;
  if (regNext == NULL)
  {
    return;
  }
  do
  {
    regNext->timeIrrigationFinish = (TSAtual + (regNext->timeIrrigationFinish - regNext->timeIrrigationStart));
    regNext->timeIrrigationStart -= ((reg->timeIrrigationFinish) - (reg->timeIrrigationStart));
    regNext->timeIrrigationStart += (TSAtual - regNext->timeIrrigationStart);

    regNext = regNext->next;
  } while (regNext != NULL);
}

void Key::setConnected(uint8_t irrigador)
{
  TRegister *reg = _regs_head;
  if (reg == NULL)
  {
    return;
  }
  do
  {
    if (reg->irrigador == irrigador)
    {
      reg->connected = true;
      reg = reg->next;
    }
    else
    {
      reg = reg->next;
    }
  } while (reg != NULL);
}

void Key::updateAllTime(uint16_t TSUpdate)
{
  TRegister *reg = _regs_head;
  if (reg == NULL)
  {
    return;
  }
  do
  {
    reg->timeIrrigationStart += TSUpdate;
    reg->timeIrrigationFinish += TSUpdate;
    reg = reg->next;
  } while (reg != NULL);
}

void Key::cleanAfterFirstRegister(uint8_t irrigador, uint8_t setor, uint32_t timeNow)
{
  TRegister *reg = searchRegister(irrigador, setor);
  TRegister *regNext = reg->next;

  reg->estado = true;
  reg->timeIrrigationFinish = timeNow;

  if (regNext == NULL)
  {
    return;
  }
  do
  {
    if (regNext != NULL)
    {
      free(regNext);
      regNext = regNext->next;
    }
  } while (regNext != NULL);
  _regs_last = reg;
  reg->next = NULL;
}

void Key::delReg(uint8_t irrigador, uint8_t setor)
{
  TRegister *reg = _regs_head;
  TRegister *regPrev = reg;
  
  if (reg == NULL)
  {
    return;
  }
  if ((_regs_head->irrigador == irrigador) && (_regs_head->setor == setor))
  {
    if ((_regs_head->irrigador == _regs_last->irrigador) && (_regs_head->setor == _regs_last->setor))
    {
      free(reg);
      _regs_head = NULL;
      _regs_last = NULL;
    }
    else
    {
      free(reg);
      _regs_head = _regs_head->next;
    }
    return;
  }
  else
  {
    do
    {
      if ((reg->irrigador == irrigador) && (reg->setor == setor))
      {
        free(reg);
        reg = reg->next;
        regPrev->next = reg;

        if (regPrev == NULL)
        {
          regPrev = NULL;
        }
        return;
      }
      else
      {
        regPrev = reg;
        reg = reg->next;
      }
    } while (reg != NULL);
  }
}

void Key::copyReg(TRegister *copy)
{
  TRegister *newreg;

  newreg = (TRegister *)malloc(sizeof(TRegister));
  *newreg = *copy;
  newreg->next = NULL;

  if (_regs_head == NULL)
  {
    _regs_head = newreg;
    _regs_last = newreg;
  }
  else
  {
    _regs_last->next = newreg;
    _regs_last = newreg;
  }
}

void Key::delRegs(void)
{
  TRegister *reg = _regs_head;
  if (reg == NULL)
  {
    return;
  }
  do
  {
    if (reg != NULL)
    {
      free(reg);
      reg = reg->next;
    }
  } while (reg != NULL);
  _regs_head = NULL;
  _regs_last = NULL;
}
