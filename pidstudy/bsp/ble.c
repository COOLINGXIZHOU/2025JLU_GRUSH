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
                        //处理数据（灯光）
                        if(rec_buff[0] == 'r' && rec_buff[1] == 'e' && rec_buff[2] == 'd')   
                        {
                                sprintf(send_buff, "red\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
													      led_showR(1);
                        }
                        else if(rec_buff[0] == 'b' && rec_buff[1] == 'l' && rec_buff[2] == 'u' && rec_buff[3] == 'e')  
                        {
                                sprintf(send_buff, "blue\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showB(1);
                        }
                        else if(rec_buff[0] == 'g' && rec_buff[1] == 'r' && rec_buff[2] == 'e' && rec_buff[3] == 'e' && rec_buff[4] == 'n')  
                        {
                                sprintf(send_buff, "green\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showG(1);
                        }
												//WASD
												else if(rec_buff[0] == 'u' && rec_buff[1] == 'p')  
                        {
                                sprintf(send_buff, "up\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showG(1);
                        }
												else if(rec_buff[0] == 'd' && rec_buff[1] == 'o' && rec_buff[2] == 'w' && rec_buff[3] == 'n')  
                        {
                                sprintf(send_buff, "down\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showG(1);
                        }
												else if(rec_buff[0] == 'l' && rec_buff[1] == 'e' && rec_buff[2] == 'f' && rec_buff[3] == 't')  
                        {
                                sprintf(send_buff, "left\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showG(1);
                        }
												else if(rec_buff[0] == 'r' && rec_buff[1] == 'i' && rec_buff[2] == 'g' && rec_buff[3] == 'h' && rec_buff[4] == 't')  
                        {
                                sprintf(send_buff, "right\r\n");
                                HAL_UART_Transmit(&huart2, (uint8_t *)send_buff, sizeof(send_buff), 50);
																led_showG(1);
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
