/**************************************************************************************************
  Filename:       IR.h
  Revised:        $Date: 2012-10-22 18:35:23 -0700 (Mon, 22 Oct 2012) $
  Revision:       $Revision: 00001 $

  Description:    IR definitions and declaration.

**************************************************************************************************/

#ifndef IR_H
#define IR_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "ioCC2530.h"
  
/*********************************************************************
 * CONSTANTS
 */
// IO Port define based on hardware 
#define IR_IN_0             P0_4               //Connect IR sensor to this pin
#define IR_IN_1             P0_5
#define IR_IN_2             1
#define IR_IN_3             1
#define IR_IN_4             1
#define IR_IN_5             1
#define IR_IN_6             1
#define IR_IN_7             1
#define LED_0_MARK_ON()     (P1_0 = 0)         //Red LED on
#define LED_0_MARK_OFF()    (P1_0 = 1)         //Red LED off
#define LED_0_IDLE_ON()     (P1_1 = 0)         //Green LED on
#define LED_0_IDLE_OFF()    (P1_1 = 1)         //Green LED off
#define LED_1_MARK_ON()              
#define LED_1_MARK_OFF()             
#define LED_1_IDLE_ON()              
#define LED_1_IDLE_OFF()    
#define LED_2_MARK_ON()              
#define LED_2_MARK_OFF()             
#define LED_2_IDLE_ON()              
#define LED_2_IDLE_OFF()    
#define LED_3_MARK_ON()              
#define LED_3_MARK_OFF()             
#define LED_3_IDLE_ON()              
#define LED_3_IDLE_OFF()    
#define LED_4_MARK_ON()              
#define LED_4_MARK_OFF()             
#define LED_4_IDLE_ON()              
#define LED_4_IDLE_OFF()    
#define LED_5_MARK_ON()              
#define LED_5_MARK_OFF()             
#define LED_5_IDLE_ON()              
#define LED_5_IDLE_OFF()    
#define LED_6_MARK_ON()              
#define LED_6_MARK_OFF()             
#define LED_6_IDLE_ON()              
#define LED_6_IDLE_OFF()    
#define LED_7_MARK_ON()              
#define LED_7_MARK_OFF()             
#define LED_7_IDLE_ON()              
#define LED_7_IDLE_OFF()    


// Bit define
#define BIT0                0x01
#define BIT1                0x02
#define BIT2                0x04
#define BIT3                0x08
#define BIT4                0x10
#define BIT5                0x20
#define BIT6                0x40
#define BIT7                0x80
  
/* This Part defined in SampleApp.h
// Event ID, 
#define SAMPLEAPP_SEND_PERIODIC_MSG_EVT       0x0001 
#define SAMPLEAPP_SEAT_0_TIMEOUT_MSG_EVT      0X0002
#define SAMPLEAPP_SEAT_1_TIMEOUT_MSG_EVT      0X0004
#define SAMPLEAPP_SEAT_2_TIMEOUT_MSG_EVT      0X0008
#define SAMPLEAPP_SEAT_3_TIMEOUT_MSG_EVT      0X0010
#define SAMPLEAPP_SEAT_4_TIMEOUT_MSG_EVT      0X0020
#define SAMPLEAPP_SEAT_5_TIMEOUT_MSG_EVT      0X0040
#define SAMPLEAPP_SEAT_6_TIMEOUT_MSG_EVT      0X0080
#define SAMPLEAPP_SEAT_7_TIMEOUT_MSG_EVT      0X0100
#define SAMPLEAPP_CHECK_CMD_ARRIVED_MSG_EVT             0X0200

// Default timeout
#define SAMPLEAPP_SEAT_DEFAULT_TIMEOUT        10000       // 10 Second  
*/
  
// Max seats in one table
#define SEAT_MAX_CNT                                    8
  
// Seat Stats
#define SEATSTAT_IDLE                                   0
#define SEATSTAT_USE                                    1
#define SEATSTAT_MARK                                   2
  
// Seat events uesd in seat structure
#define SEAT_CHECK_OBSTRUCTION_TRUE_EVT                 0X01
#define SEAT_CHECK_OBSTRUCTION_FALSE_EVT                0X02
#define SEAT_CHECK_TIMEOUT_ON_EVT                       0X04
#define SEAT_CHECK_CMD_ARRIVED_EVT                      0X08  

// Sensor useful level, high or low
#define IR_USEFUL_LEVEL                                 0  

/*********************************************************************
 * TYPEDEFS
 */

// 定义某个座位的结构类型
typedef struct {
  uint8 gid;            // 组号，即ENDPOINT号，表示该座位属于哪张桌子
  uint8 uid;            // 用户号，即座位号
  uint8 stat;           // 座位状态
  uint8 events;         // 当前座位接收到的事件，可有多个
} IRSeat_t;

  
/*********************************************************************
 * EXTERN VARIABLES
 */
/*
// 记录一张桌子上多个座位的信息
extern IRSeat_t seatTable[SEAT_MAX_CNT];  //将此变量放置SampleApp.c中
*/

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * FUNCTIONS
 */

/*
 * IR module init
 */
extern uint8 IR_init( void );

/*
 * Get events of a seat, store them into the seat structure
 */
extern uint8 IR_getEvents( IRSeat_t *seatPt );

/*
 * Process events of a seat
 */
extern uint8 IR_processEvent( IRSeat_t *seatPt );

/*
 * 
 */

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* IR_H */
