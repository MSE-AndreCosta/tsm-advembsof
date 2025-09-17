// stl
#include <chrono>

// zpp-lib
#include "zpp_include/thread.hpp"
#include "zpp_include/this_thread.hpp"
#include "zpp_include/digital_out.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(blinky, CONFIG_APP_LOG_LEVEL);

void blink()
{
	zpp_lib::DigitalOut led(zpp_lib::DigitalOut::PinName::LED0);
	using namespace std::literals;
	static std::chrono::milliseconds blinkInterval = 1000ms;

	while (true) {
		led = !led;
		zpp_lib::ThisThread::sleep_for(blinkInterval);
	}
}

int main(void)
{
	LOG_DBG("Running on board %s", CONFIG_BOARD_TARGET);
	LOG_DBG("Starting thread");
	zpp_lib::Thread thread;
	auto res = thread.start(blink);
	if (!res) {
		LOG_ERR("Could not start thread (%d)", static_cast<int>(res.error()));
		return -1;
	}
	res = thread.join();
	if (!res) {
		LOG_ERR("Could not join thread (%d)", static_cast<int>(res.error()));
		return -1;
	}
	return 0;
}
