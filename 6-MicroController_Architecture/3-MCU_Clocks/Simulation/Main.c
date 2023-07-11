// Function to delay for a certain number of microseconds
void delay_us(uint32_t us) {
    us *= 9;  // Adjust this value for your particular STM32 core clock frequency
    while (us--) {
        __asm__ volatile("nop");
    }
}

int main(void) {
    // Enable the GPIOC peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Set GPIOC pin 13 as output
    GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
    GPIOC->CRH |= GPIO_CRH_MODE13;

    while (1) {
        // Toggle the LED
        GPIOC->ODR ^= GPIO_ODR_ODR13;

        // Delay for 1 second
        delay_us(1000000);
    }
}