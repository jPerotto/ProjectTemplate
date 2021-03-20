#ifndef KEY_H
#define KEY_H

#include "Arduino.h"

typedef struct TRegister
{
  uint8_t irrigador;
  uint8_t setor;
  bool estado;
  bool connected;
  uint32_t timeIrrigationStart;
  uint32_t timeIrrigationFinish;
  struct TRegister *next;
} TRegister;

class Key
{
private:
  TRegister *_regs_head;
  TRegister *_regs_last;

public:
  Key(void);
  TRegister *searchRegister(uint8_t irrigador, uint8_t setor);
  TRegister *firstRegister(void);
  TRegister *lastRegister(void);
  void addReg(uint8_t irrigador, uint8_t setor, bool estado, uint32_t timeIrrigationStart, uint32_t timeIrrigationFinish);
  void reajustTime(uint8_t irrigador, uint8_t setor, uint32_t TSAtual);
  void setConnected(uint8_t irrigador);
  void updateAllTime(uint16_t TSUpdate);
  void cleanAfterFirstRegister(uint8_t irrigador, uint8_t setor, uint32_t timeNow);
  void delReg(uint8_t irrigador, uint8_t setor);
  void copyReg(TRegister *copy);
  void delRegs(void);
};

#endif
