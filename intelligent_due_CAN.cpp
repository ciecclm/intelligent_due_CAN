//
//  intelligent_due_CAN.cpp
//
//
//  Created by 朝力萌 on 2016/11/26.
//
//
//2018年5月30日 科亚4850-2E
#include "intelligent_due_CAN.h"
CIntelligent_due_CAN::CIntelligent_due_CAN()
{
   // driver_group=0;
    //driver_number=0;
    //driver_mode=3;
    driver_mode=1;
}

void CIntelligent_due_CAN::resetdriver(int drv_ID)
{
    driver_ID=drv_ID;
    outgoing.id=(0x600+driver_ID);
    outgoing.length=8;
    outgoing.extended = false;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x23002001;
    Can0.sendFrame(outgoing);
    delay(500);
}
void CIntelligent_due_CAN::setmode(int group=0,int number=0,int mode=3 )
{
    //CAN_FRAME outgoing;
    //outgoing.id = temp;//0x021;
    outgoing.id = (0x600+driver_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=0x01;
    outgoing.data.bytes[4]=0x00;
    outgoing.data.bytes[5]=0x00;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
    delay(500);
}

void CIntelligent_due_CAN::speedwheel(int temp_velocity,int moto_ID=0)
{
    //CAN_FRAME outgoing;
    outgoing.id = (0x600+driver_ID);
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=moto_ID&0xff;
    outgoing.data.bytes[4]=(temp_velocity>>8)&0xff;
    outgoing.data.bytes[5]=(temp_velocity)&0xff;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;
    Can0.sendFrame(outgoing);
}
void CIntelligent_due_CAN::initdriver(int baud=CAN_BPS_1000K,int drv_ID=1,int mode=3)
{
    Can0.begin(baud);
    Can0.watchFor();
    resetdriver(drv_ID);
    //setmode(group,number,mode);
}
void CIntelligent_due_CAN::testwheel()
{
    outgoing.id = 0x600+driver_ID;
    outgoing.extended = false;
    outgoing.length=8;
    outgoing.priority = 4; //0-15 lower is higher priority
    outgoing.data.high=0x00;
    outgoing.data.low=0x00;
    outgoing.data.bytes[0]=0x23;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[2]=0x20;
    outgoing.data.bytes[3]=0x02;
    outgoing.data.bytes[4]=0xf4;
    outgoing.data.bytes[5]=0x01;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[7]=0x00;/*
    outgoing.data.bytes[7]=0x23;
    outgoing.data.bytes[6]=0x00;
    outgoing.data.bytes[5]=0x20;
    outgoing.data.bytes[4]=0x01;
    outgoing.data.bytes[3]=0xf4;
    outgoing.data.bytes[2]=0x01;
    outgoing.data.bytes[1]=0x00;
    outgoing.data.bytes[0]=0x00;*/
    Can0.sendFrame(outgoing);
    
}

