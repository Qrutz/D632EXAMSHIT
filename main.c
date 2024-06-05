#include <stdio.h>
#include <stdint.h>

uint8_t pack_bits(uint8_t engine_on, uint8_t gear_pos, uint8_t key_pos, uint8_t brake1, uint8_t brake2)
{
    // Ensure the values are within the specified ranges
    if (engine_on > 1 || gear_pos > 4 || key_pos > 2 || brake1 > 1 || brake2 > 1)
    {
        return 0; // Return 0 if any value is out of range
    }

    // Pack the bits into a byte
    uint8_t packed = (engine_on << 7) | (gear_pos << 4) | (key_pos << 2) | (brake1 << 1) | brake2;

    printf("Hexadecimal: %02X\n", packed);

    return packed;
}

// Function to unpack bits from a byte
void unpack_bits(uint8_t packed, uint8_t *engine_on, uint8_t *gear_pos, uint8_t *key_pos, uint8_t *brake1, uint8_t *brake2)
{
    // Unpack the bits from the byte
    *engine_on = (packed >> 7) & 0x01;
    *gear_pos = (packed >> 4) & 0x07;
    *key_pos = (packed >> 2) & 0x03;
    *brake1 = (packed >> 1) & 0x01;
    *brake2 = packed & 0x01;
}

int main()
{
    // Example values
    uint8_t engine_on = 1;
    uint8_t gear_pos = 3;
    uint8_t key_pos = 2;
    uint8_t brake1 = 1;
    uint8_t brake2 = 0;

    uint8_t packed_byte = pack_bits(engine_on, gear_pos, key_pos, brake1, brake2);
    printf("Packed byte: %02X\n", packed_byte);

    uint8_t unpacked_engine_on, unpacked_gear_pos, unpacked_key_pos, unpacked_brake1, unpacked_brake2;
    unpack_bits(packed_byte, &unpacked_engine_on, &unpacked_gear_pos, &unpacked_key_pos, &unpacked_brake1, &unpacked_brake2);

    printf("Unpacked values:\n");
    printf("  engine_on = %u\n", unpacked_engine_on);
    printf("  gear_pos = %u\n", unpacked_gear_pos);
    printf("  key_pos = %u\n", unpacked_key_pos);
    printf("  brake1 = %u\n", unpacked_brake1);
    printf("  brake2 = %u\n", unpacked_brake2);

    return 0;
}