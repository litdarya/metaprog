#pragma once

enum class patterns_options {
	Mediator,
	Proxy,
	Observer,
};

enum class mediator_events {
    click,
    print,
};

enum observer_events {
	asked_name,
	click,
	print,
	COUNT,
};

template <patterns_options T>
class Pattern;