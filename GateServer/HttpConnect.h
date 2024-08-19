#pragma once
#include"const.h"
#include <unordered_map>


class HttpConnect:public std::enable_shared_from_this<HttpConnect>
{
public:
	friend class LogicSystem;
	HttpConnect(boost::asio::io_context & ioc);
	void Start();
	tcp::socket& GetSocket() {
		return _socket;
	}
private:
	void CheckDeadline();
	void WriteResponse();
	void HandleReq();
	void PreParseGetParam();
	tcp::socket _socket;
	beast::flat_buffer _buffer{ 8192 };
	http::request<http::dynamic_body> _request;//¶¯Ì¬body
	http::response<http::dynamic_body> _response;
	net::steady_timer deadline_{
		_socket.get_executor(),std::chrono::seconds(60)//¼ì²â³¬Ê±
	};
	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;

};

