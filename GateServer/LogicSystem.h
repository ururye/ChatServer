#pragma once
#include"const.h"

class HttpConnect;
typedef std::function<void(std::shared_ptr<HttpConnect>)>HttpHandler;


class LogicSystem :public Singleton<LogicSystem> {
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem() {};
	bool HandleGet(std::string,std::shared_ptr<HttpConnect>);
	bool HandlePost(std::string, std::shared_ptr<HttpConnect>);
	void RegPost(std::string url, HttpHandler handler);
	void RegGet(std::string,HttpHandler handler);
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;
	std::map<std::string, HttpHandler> _get_handlers;
};