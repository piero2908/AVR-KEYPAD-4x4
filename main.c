#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

char variable;
char matriz[4][4] = {{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

void pinc_config(uint8_t x){
	if(x == 0){
		PORTC |= (0<<PORTC4)|(1<<PORTC5);
		PORTD |= (1<<PORTD2)|(1<<PORTD3);
	}
	else if(x == 1){
		        //PORTC |= (1<<PORTC4)|(0<<PORTC5);
		        //PORTD |= (1<<PORTD2)|(1<<PORTD3);
	}
}

void get_keypad(){
	uint8_t col, colAux, mask;
	uint8_t pincS = PINC;
	
	for(col = 0; col < 4; col++){
		if(col == 0){
			pinc_config(col);
			for(mask = 0x08; mask; mask>>=1){
				if( !(mask & PINC) ){
					PORTD ^= (1<<PORTD4);
					_delay_ms(200);
				}
			}
		}
		else if(col == 1){
			pinc_config(col);
			for(mask = 0x08; mask; mask>>=1){
				if( !(mask & PINC) ){
					PORTD ^= (1<<PORTD4);
					_delay_ms(200);
				}
			}
		}
	}
	
	
	//    return matriz[rowsAux,colAux];
}

void pin_config(){
	DDRC |= (0<<DDC0)|(0<<DDC1)|(0<<DDC2)|(0<<DDC3)|(1<<DDC4)|(1<<DDC5);
	DDRD |= (1<<DDD2)|(1<<DDD3);
	
	//LED
	DDRD |= (1<<DDD4);
	
	//Activando los PULL-UPS y las salidas a 1 lógico
	PORTC |= (1<<PORTC0)|(1<<PORTC1)|(1<<PORTC2)|(1<<PORTC3); //PULL UPS ROWS PORTC 0 - 3
	
}

int main(){
	
	pin_config();
	while (1) {
		get_keypad();
		

	}
	return 0;
}
