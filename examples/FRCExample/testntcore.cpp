/* simple nettab client example derived from ntcore/manualExamples/client.cpp */

#include "networktables/NetworkTableInstance.h"

#include <chrono>
#include <climits>
#include <cstdio>
#include <thread>
#include <cstddef>

int main() 
{
    auto inst = nt::GetDefaultInstance();
    nt::AddLogger(inst,
                [](const nt::LogMessage& msg) {
                  std::fputs(msg.message.c_str(), stderr);
                  std::fputc('\n', stderr);
                },
                0, UINT_MAX);
    nt::StartClient(inst, "127.0.0.1", 1735);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto foo = nt::GetEntry(inst, "/SmartDashboard/Vision/foo");
    auto foo_val = nt::GetEntryValue(foo);
    if (foo_val && foo_val->IsDouble())
        std::printf("Got foo: %g\n", foo_val->GetDouble());
    else
        nt::SetEntryValue(foo, nt::Value::MakeDouble(3.));
    
    auto bar = nt::GetEntry(inst, "/SmartDashboard/Vision/bar");
    nt::SetEntryValue(bar, nt::Value::MakeBoolean(false));
    nt::SetEntryFlags(bar, NT_PERSISTENT);
    
    auto bar2 = nt::GetEntry(inst, "/SmartDashboard/Vision/bar2");
    nt::SetEntryValue(bar2, nt::Value::MakeBoolean(true));
    nt::SetEntryValue(bar2, nt::Value::MakeBoolean(false));
    nt::SetEntryValue(bar2, nt::Value::MakeBoolean(true));
    std::this_thread::sleep_for(std::chrono::seconds(10));

    int icnt = 0;
    auto counter = nt::GetEntry(inst, "/SmartDashboard/Vision/counter");
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        nt::SetEntryValue(counter, nt::Value::MakeDouble(icnt++));
    }

    return 0;
}
