#include "headfile.h"



char send_buff[20];
uint8_t rec_data, count;
uint8_t rec_flag;
uint8_t rec_buff[20];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
        if(huart->Instance == USART2)
        {
                //HAL_UART_Transmit(huart, &rec_data, 1, 50);
                TIM13->CNT = 0;
                rec_flag = 1;
                rec_buff[count] = rec_data;
                count++;
                HAL_UART_Receive_IT(huart, &rec_data, 1);
        }
}

void ble_uart_data_rec(void)
{
        if(rec_flag)
        {
                if(TIM13->CNT > 15)  //数据接收完成
                {
                        //处理数据
                        if(rec_buff[0] == 'r' && rec_buff[1] == 'e' && rec_buff[2] == 'd')   //lan
                        {
                                sprintf(send_buff, "red\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
													      led_showR(1);
                        }
                        else if(rec_buff[0] == 'q' && rec_buff[1] == 'i' && rec_buff[2] == 'a' && rec_buff[3] == 'o')  //qiao
                        {
                                sprintf(send_buff, "qiao\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showB(1);
                        }
                        else if(rec_buff[0] == 'b' && rec_buff[1] == 'e' && rec_buff[2] == 'i')  //bei
                        {
                                sprintf(send_buff, "bei\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
                        }
                        else
                        {
                                sprintf(send_buff, "error!\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);                        
                        }
                        
                        rec_flag = 0;
                        for(int i=0; i<count; i++)
                                rec_buff[i] = 0;
                        count = 0;
                }
        }
}
