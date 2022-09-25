#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no-main.c"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    struct Message msg;
    memset(&msg, 0, sizeof(struct Message));

    decode_msg(&msg, Data, Size)

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