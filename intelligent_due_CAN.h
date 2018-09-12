//
//  intelligent_due_CAN.h
//  
//
//  Created by 朝力萌 on 2016/11/26.
//
//
//2018年5月30日 科亚4850-2E
#ifndef intelligent_due_CAN_h
#define intelligent_due_CAN_h
#include "variant.h"
#include "due_can.h"
#endif /* intelligent_due_CAN_h */

class CIntelligent_due_CAN
{
private:
    //int driver_group;
    //int driver_number;
    int driver_mode;
    int driver_ID;
    CAN_FRAME outgoing;
   // void resetdriver(int group,int number );
    void resetdriver(int driver_ID );
    void setmode(int group,int number,int mode );
public:
    CIntelligent_due_CAN();
    //void initdriver(int baud,int group,int number,int mode);
    void initdriver(int baud,int drv_ID,int mode);
    
    //void speedwheel(int temp_velocity,int group,int number);
    void speedwheel(int temp_velocity,int drv_ID);
    void setposition(int position,int moto_ID=0);
    void testwheel();
};
