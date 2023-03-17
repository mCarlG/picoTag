#include "pico_tag.h"

uint8_t adv_data[] = {
    0x1e,
    0xff,
    0x4c, 0x00,
    0x12, 0x19,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00,
    0x00,
};
uint8_t adv_data_len = sizeof(adv_data);

int le_setup(void)
{
    sm_init();

    uint16_t adv_int_min = 0x0640;
    uint16_t adv_int_max = 0x0C80;
    uint8_t adv_typ = 0x03;
    bd_addr_t ble_addr = {0xde, 0xad, 0xbe, 0xef, 0x41, 0x41};

    gap_random_address_set(ble_addr);
    gap_advertisements_set_params(adv_int_min, adv_int_max, adv_typ, GAP_RANDOM_ADDRESS_TYPE_STATIC, ble_addr, 0x7, 0x00);
    gap_advertisements_set_data(adv_data_len, adv_data);
    gap_advertisements_enable(1);
}


int btstack_main(void)
{
    le_setup();
    hci_power_control(HCI_POWER_ON);
    return 0;
}


int main(void)
{
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("CYW43 initialization failure.");
        return -1;
    }
    btstack_run_loop_base_init();
    btstack_main();
    btstack_run_loop_execute();
    return 0;
}
