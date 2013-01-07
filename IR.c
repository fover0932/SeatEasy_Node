/**************************************************************************************************
  Filename:       IR.c
  Revised:        $Date: 2012-10-22 17:05:27 -0700 ( Mon 22 Oct 2012 )$
  Revision:       $Revision: 00001 $

  Description:    该模块利用按键来仿真红外测障传感器。当按键按下时，表示检测到障
                  碍，当按键松开时，表示检测不到障碍.
                  当检测到障碍，就将状态更新到状态信息表中，并打开对应的状态指示
                  灯。
                  EP节点定时将状态信息打包发送给CD节点，CD节点通过串口将信息又发
                  送给PC,PC则通过串口工具显示出来。
                  在PC的串口工具中发送指令，该指令通过串口到达CD，再通过无线网络
                  到达ED，ED收到指令后，执行对应的动作，如修改状态信息表。

**************************************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "hal_types.h"
#include "IR.h"
#include "SampleApp.h"

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * LOCAL VARIABLES
 */

/*********************************************************************
 * LOCAL FUNCTIONS
 */
//uint8 IR_setSeat( IRSeat_t *seatp, uint8 gid, uint8 uid, uint8 stat );
//uint8 IR_initSeat( uint8 gid, uint8 seatCnt);
uint8 IR_initHardware( void );
uint8 IR_updateLed( uint8 uid, uint8 stat );

/*********************************************************************
 * @fn      IR_setSeat
 *
 * @brief   Set value for a seat structure.
 *
 * @param   
 * @param   seatPt - seat pointer.
 *          gid    - groupID. Valid entries: ENDPOINT.
 *          uid    - userID, seat number.
 *          stat   - seat stat. Valid entries:
 *                   SEATSTAT_IDLE
 *                   SEATSTAT_USE
 *                   SEATSTAT_MARK.
 *
 * @return  0 if success.
 */
/*
uint8 IR_setSeat( IRSeat_t *seatPt, uint8 gid, uint8 uid, uint8 stat ){
  seatPt->gid = gid;
  seatPt->uid = uid;
  seatPt->stat = stat;
  return 0;
}
*/

/*********************************************************************
 * @fn      IR_initSeat
 *
 * @brief   init every seat.
 *
 * @param   gid -     groupID. Valid entries: ENDPOINT.
 *          seatCnt - seat counts.
 * @return  0 if success.
 */
/*
uint8 IR_initSeat( uint8 gid, uint8 seatCnt){
  uint8 i;
  for( i=0; i<seatCnt; i++){
    IR_setSeat(&seatTable[i], gid, i, SEATSTAT_IDLE); 
  }
  return 0;
}
*/

/*********************************************************************
 * @fn      IR_initHardware
 *
 * @brief   
 *
 * @param   none
 * @return  0 if success.
 */
uint8 IR_initHardware( void ){
  // Init IO output
  P1DIR |= BIT0 + BIT1;
  LED_0_MARK_OFF();
  LED_0_IDLE_OFF();
  
  // Init IO Input
  P0DIR &=~ BIT4 + BIT5;

  return 0;
}

/*********************************************************************
 * @fn      IR_updateLed
 *
 * @brief   
 *   
 * @param   seatPt - seat pointer.
 * @return  0 if success.
 */
uint8 IR_updateLed( uint8 uid, uint8 stat ){
  if( stat != SEATSTAT_USE ){
    switch( uid ){
    case 0:
      LED_0_MARK_OFF();
      LED_0_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_0_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_0_MARK_ON();
      }
      break;
    case 1:
      LED_1_MARK_OFF();
      LED_1_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_1_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_1_MARK_ON();
      }
      break;
    case 2:
      LED_2_MARK_OFF();
      LED_2_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_2_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_2_MARK_ON();
      }
      break;
    case 3:
      LED_3_MARK_OFF();
      LED_3_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_3_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_3_MARK_ON();
      }
      break;
    case 4:
      LED_4_MARK_OFF();
      LED_4_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_4_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_4_MARK_ON();
      }
      break;
    case 5:
      LED_5_MARK_OFF();
      LED_5_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_5_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_5_MARK_ON();
      }
      break;
    case 6:
      LED_6_MARK_OFF();
      LED_6_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_6_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_6_MARK_ON();
      }
      break;
    case 7:
      LED_7_MARK_OFF();
      LED_7_IDLE_OFF();
      if( stat == SEATSTAT_IDLE ){
        LED_7_IDLE_ON();
      }
      if( stat == SEATSTAT_MARK ){
        LED_7_MARK_ON();
      }
      break;
    }
  }
  else{
    LED_0_MARK_OFF();
    LED_0_IDLE_OFF();
    LED_1_MARK_OFF();
    LED_1_IDLE_OFF();
    LED_2_MARK_OFF();
    LED_2_IDLE_OFF();
    LED_3_MARK_OFF();
    LED_3_IDLE_OFF();
    LED_4_MARK_OFF();
    LED_4_IDLE_OFF();
    LED_5_MARK_OFF();
    LED_5_IDLE_OFF();
    LED_6_MARK_OFF();
    LED_6_IDLE_OFF();
    LED_7_MARK_OFF();
    LED_7_IDLE_OFF();
  }
  return 0;
}

/*********************************************************************
 * @fn      Module_LocalFunc
 *
 * @brief   
 *
 * @param   
 * @param   param - param brief. Valid entries:
 *                  PAREM_VALUE_1
 *                  PARAM_VALUE_2
 *                  ...
 *
 * @return  none
 */

/*********************************************************************
 * PUBLIC FUNCTIONS
 */
uint8 IR_init( void );
uint8 IR_getEvents( IRSeat_t *seatPt );
uint8 IR_processEvent( IRSeat_t *seatPt );

/*********************************************************************
 * @fn      Module_PublicFunc
 *
 * @brief   
 *
 * @param   none
 * @return  0 if success.
 */
uint8 IR_init( void ){
  IR_initHardware();
  return 0;
}

/*********************************************************************
 * @fn      IR_getEvents
 *
 * @brief   Get events of a seat, store them into the seat structure.
 *
 * @param   seatPt - seat pointer. 
 * @return  0 if success.
 */
uint8 IR_getEvents( IRSeat_t *seatPt ){
  // Save current events already had
  uint8 events=0;
  events |= seatPt->events;
  
  // Check obstruction event  
  switch( seatPt->uid ){
  case 0:
    if( IR_IN_0 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 1:
    if( IR_IN_1 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 2:
    if( IR_IN_2 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 3:
    if( IR_IN_3 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 4:
    if( IR_IN_4 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 5:
    if( IR_IN_5 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 6:
    if( IR_IN_6 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  case 7:
    if( IR_IN_7 == IR_USEFUL_LEVEL )
      events |= SEAT_CHECK_OBSTRUCTION_TRUE_EVT;
    else
      events |= SEAT_CHECK_OBSTRUCTION_FALSE_EVT;
    break;
  default:
    break;
  }
  
  // Check command arrived event
  
  seatPt->events |= events;
  
  return 0;
}

/*********************************************************************
 * @fn      IR_processEvent
 *
 * @brief   Process events of a seat.
 *
 * @param   seatPt - seat pointer.
 * @return  0 if success.
 */
uint8 IR_processEvent( IRSeat_t *seatPt ){
  uint8 uid, events, stat;
  uid = seatPt->uid;
  events = seatPt->events;
  stat = seatPt->stat;
  
  if( events ){
    switch( stat ){
    case SEATSTAT_IDLE:
      if( events & SEAT_CHECK_OBSTRUCTION_TRUE_EVT ){
        seatPt->stat = SEATSTAT_USE;
      }
      else if( events & SEAT_CHECK_CMD_ARRIVED_EVT ){
        seatPt->stat = SEATSTAT_MARK;
        
        // Start timeout timer
        SampleApp_StartTimerEx( uid );
      }
      break;
    case SEATSTAT_USE:
      if( events & SEAT_CHECK_OBSTRUCTION_FALSE_EVT ){
        seatPt->stat = SEATSTAT_MARK;
        
        // Start timeout timer
        SampleApp_StartTimerEx( uid );
      }
      break;
    case SEATSTAT_MARK:
      if( events & SEAT_CHECK_TIMEOUT_ON_EVT ){
        seatPt->stat = SEATSTAT_IDLE;
      }
      else if( events & SEAT_CHECK_OBSTRUCTION_TRUE_EVT ){
        seatPt->stat = SEATSTAT_USE;
      }
      break;
    default:
      break;
    }
    
    // Update indicator
    IR_updateLed( uid, seatPt->stat);
    
    // Clear all events
    seatPt->events = 0;
  }
  return 0;
}

/*********************************************************************
 * @fn      Module_PublicFunc
 *
 * @brief   
 *
 * @param   none
 * @return  none
 */

/*********************************************************************
*********************************************************************/
