int period;
int duty;
const int pin = 7;

void setup() {
    pinMode(pin, OUTPUT);
}

void loop() {
    
    set_period(10000); //주기를 10ms로 설정.
    // 0.5초 동안 최소 밝기에서 최대 밝기로 변화
    for(int d = 0; d <= 100; d+=2) {
        set_duty(d);
    }
    
    // 0.5초 동안 최대 밝기에서 최소 밝기로 변화
    for(int d = 100; d >= 0; d-=2) {
        set_duty(d);
    }
    
    
    set_period(1000); //주기를 1ms로 설정.
    // 0.5초 동안 최소 밝기에서 최대 밝기로 변화
    for(int d = 0; d <= 100; d++) {
        set_duty(d);
    }
    
    // 0.5초 동안 최대 밝기에서 최소 밝기로 변화
    for(int d = 100; d >= 0; d--) {
        set_duty(d);
    }
    

    set_period(100); //주기를 0.1ms로 설정.
    // 0.5초 동안 최소 밝기에서 최대 밝기로 변화
    for(int d = 0; d <= 100; d++) {
        set_duty(d);
    }
    
    // 0.5초 동안 최대 밝기에서 최소 밝기로 변화
    for(int d = 100; d >= 0; d--) {
        set_duty(d);
    }

    while(1){}
}

// 주기를 설정하는 함수
void set_period(int p) {
    period = p;
}

// 듀티를 설정하는 함수
void set_duty(int d) {
    duty = d;
        
    int lowTime = period / 100 * duty;   // LOW 시간 계산
    int highTime = period - lowTime;      // HIGH 시간 계산

    if(5000<period){                    // duty를 1씩 올리지 못하는 경우 
        digitalWrite(pin, 0);
        delayMicroseconds(lowTime);
        digitalWrite(pin, 1);
        delayMicroseconds(highTime);
    }
    else{                               // duty를 1씩 올리는 경우
        for(int i=0;i<5000/period;i++){
        digitalWrite(pin, 0);
        delayMicroseconds(lowTime);
        digitalWrite(pin, 1);
        delayMicroseconds(highTime);
        }
    }
}
