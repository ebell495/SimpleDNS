#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no-main.c"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    struct Message msg;
    memset(&msg, 0, sizeof(struct Message));

    if (decode_msg(&msg, Data, Size) == 0) {
        uint8_t* buffer = (uint8_t*) malloc((Size + 1) * 16);
        encode_msg(&msg, &buffer);
    }

    if (msg.questions)
        free_questions(msg.questions);
    if (msg.answers)
        free_resource_records(msg.answers);
    if (msg.authorities)   
        free_resource_records(msg.authorities);
    if (msg.additionals)
        free_resource_records(msg.additionals);

    memset(&msg, 0, sizeof(struct Message));
    return 0;
}