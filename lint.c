#include "log_debug.h"

static const char* const data_rx_commands[] = {
    "RemoteStartTransaction",
    "RemoteCancelTransaction",
    "RemoteStopTransactionRequest",
    "UpdateFirmware",
    "Reset",
    "GetDiagnostics",
    "TriggerMessage",
    "UnlockConnector",
};

int main(void)
{
  printf("sizeof data_rx_commands %ld\n", sizeof(data_rx_commands));
  printf("sizeof data_rx_commands[0] %ld\n", sizeof(data_rx_commands[0]));
}
