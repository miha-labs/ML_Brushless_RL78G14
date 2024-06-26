
/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include	"Communication.h"

#include	"../Control.h"
#include	"../Utility/Log.h"
#include	"../../Interface/ML_UART.h"


/* -----------------------------------------------------------------------------
	Local Macro
----------------------------------------------------------------------------- */
#define	RX_HEADER	0xAB
#define	TX_HEADER	0xBA
#define	TX_SIZE	81		// 送信データ数


/* -----------------------------------------------------------------------------
	Local Variable
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local Structure
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local function
----------------------------------------------------------------------------- */
static int16_t bytesToInt16(uint8_t *bytes)
{
	int16_t i16 = 0;
	
	i16 |= (int16_t)( bytes[0]<<0 );
	i16 |= (int16_t)( bytes[1]<<8 );
	
	return i16;
}


static void int16ToBytes(int16_t i16, uint8_t *bytes)
{
	bytes[0] = (uint8_t)( (i16>>0) & 0x00FF );
	bytes[1] = (uint8_t)( (i16>>8) & 0x00FF );
}


/* -----------------------------------------------------------------------------
	private function
----------------------------------------------------------------------------- */
static bool isReceivePacket(int16_t *data)
{
	uint8_t rx_buf[3] = {0};
	
	if( !UART_Receive_3byte(rx_buf) )	return false;
	
	if( rx_buf[0]!=RX_HEADER )			return false;
	
	*data = bytesToInt16(rx_buf+1);
	
	return true;
}


static void generatePacket(uint8_t *data, uint16_t size)
{
	data[0] = TX_HEADER;
	
	uint16_t count = 1;
	uint16_t end_speed = (size-1)/2;	// ヘッダを除いた半分
	uint16_t end_current = size;
	
	// 速度データ
	while(count<end_speed)
	{
		int16ToBytes( Log_ReadSpeed(), data+count );
		count+=2;
	}
	
	// 電流データ
	while(count<end_current)
	{
		int16ToBytes( Log_ReadCurrent(), data+count );
		count+=2;
	}
}


/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
void Com_Startup(void)
{
	UART_Startup();
}


void Com_Task(void)
{
	int16_t rx_data = 0;
	if( !isReceivePacket(&rx_data) ) return;
	Ctr_SetTargetSpeed(rx_data);
		
	static uint8_t tx_data[TX_SIZE] = {0};
	//uint8_t tx_data[TX_SIZE] = {0};
	generatePacket(tx_data, TX_SIZE);
	UART_Transmit(tx_data, TX_SIZE);
}

