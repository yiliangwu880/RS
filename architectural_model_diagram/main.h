#pragma once

//用类图描述框架结构

class boost {};
class protobuf3 {};
class mysql_connector : public boost{};
class libevent {};
class LuaBridge {};
class lua {};

////////////////////////////////////////////////
class cpp_cfg {};

////////////////////////////////////////////////
class libevent_cpp : public libevent {};
class svr_util {};

////////////////////////////////////////////////
class acc_proto {};
class access_svr : public libevent_cpp, public svr_util, public acc_proto {};
class acc_driver : public libevent_cpp, public svr_util, public acc_proto {};

////////////////////////////////////////////////
class mf_proto {};
class mf_driver : public mf_proto, public libevent_cpp {};
class mf_svr : public libevent_cpp, public svr_util, public mf_proto {};

////////////////////////////////////////////////
class db_proxy_svr : public libevent_cpp, public svr_util, public protobuf3, public mysql_connector {};
class db_driver : public libevent_cpp, public svr_util, public protobuf3 {};

////////////////////////////////////////////////
class cpp_lua_mgr : public LuaBridge, public lua {};

////////////////////////////////////////////////
class simple_web_svr : public libevent_cpp, public svr_util {};