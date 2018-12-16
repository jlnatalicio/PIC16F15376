/*
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 15 de Dezembro de 2018, 22:30
 * codigo simples para acender um led em um determinado terminal de uma determinada porta.
 * tambem conhecido como "ola mundo"
 */


#include <xc.h>
#include <pic16f15376.h>

int main()
{
    //1 - configurar terminais como saída ou entrada
    TRISD = 0b00000000;     //registrador de configuracao I/O -> se bit = '0', defini-se como saida; se bit = '1', defini-se como entrada
    
    //1.1 - configurar terminais como analogicos ou digitais (opcional)
    ANSELD = 0b00000000;            /*registrador de configuracao AN/DG -> se bit = '0', defini-se como digital; se bit = '1', 
                                    *defini-se como analogico
                                    *obs: o uC mantem o registrador por padrao como setado (I/O analogico). nao ha grandes problemas, mas 
                                    *pode haver comportamento inesperado da porta (vide datasheet). Por isso, se utilizar alguma porta 
                                    *apenas como I/O digital, limpe este reg, para garantir o funcionamento correto */
    
    //2 - setar bit(s) desejado(s)
    PORTD = 0b00000001;             //seta bit 0 do PORTD, que foi configurado como saída, ou seja: RD0 = '1' = 5 Volts (VCC)
  
    //EXTRA - limpar bit(s) desejado(s) -> (facilita a visualização do bit em nivel lógico 0 ou 1 na simulacao)
    PORTD = 0b00000000;             //limpa bit 0 do PORTD, que foi configurado como saída, ou seja: RD0 = '0' = 0 Volts (GND)
    
    return 0;
} 
