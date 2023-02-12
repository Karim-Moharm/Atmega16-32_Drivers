/*
 * uart_APP.c
 *
 * Created: 12/3/2022 1:56:48 PM
 *  Author: YN
 */ 

/*
int main(void)
{  // send 
	
	DIO_INIT();
	LCD_INIT();
	//UART_INIT();
	SPI_MasterINIT(F_osc4);
	
	
// 	UART_TX('s');
// 	UART_TX('a');
// 	
	/ *void UART_SendString(u8* str);* /
	
/ *
	u8 y=0;
	UART_Send_Int(198045);* /
	u8 str[100]={0};
		
	while(1)
	{
		UART_SendString_ChkSum("Karim");
		_delay_ms(2000);
		UART_SendString_ChkSum("Moharm");
		UART_Receive_String(str);
		UART_Send_String(str);
		//u8 msg[]="hello world";
		//send_string(msg);
		
	/ *	LCD_writeNumber_IN(1,0,y);
		y++;
		if(y==10){
			y=0;
		}
		* /
		/ *UART_ReceiveString(str);
		UART_SendString("feel the pain");* /
	}
	
	
}*/