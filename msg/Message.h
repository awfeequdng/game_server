/*
 * Message.h
 *
 *  Created on: 2015年12月28日
 *      Author: zhangyalei
 */

#ifndef MSG_MESSAGE_H_
#define MSG_MESSAGE_H_

/*消息ID说明
100000-109999		Client--->Login,Gate
110000-119999  	Client--->Chat
120000-129999		Client--->Game
130000-139999		Client--->Master
140000-149999		Login,Game,Master,Chat<--->Gate
150000-159999  Game<--->DB
160000-169999		Game<--->Master
170000-179999		Master<--->DB
180000-189999		Game--->LogStream		操作流水日志
190000-199999
300000-309999		ActiveMessage			服务器发到客户端主动消息
400000-499999		InnerMessage			服务器内部消息

500000-500999		Login,Gate->Client
520000-529999		Game->Client
530000-539999		Master->Client
540000-549999		Chat->Client
550000-559999		DB-->Game
*/

enum {
	CLIENT_GATE_MESSAGE_START 					= 100000,
	CLIENT_GATE_MESSAGE_END 					= 109999,
	CLIENT_GAME_MESSAGE_START 					= 120000,
	CLIENT_GAME_MESSAGE_END 					= 129999,
};

enum Client_Login_Message {
	REQ_CLIENT_REGISTER 							= 	100000,  //注册
	REQ_CLIENT_LOGIN 									= 	100001,  //登录
	REQ_CONNECT_GATE									=	100002,	//客户端登录gate
	REQ_HEARTBEAT 										=	100003,	//心跳
};

enum Login_Client_Message {
	RES_CLIENT_REGISTER                = 500000,  //注册(返回)
	RES_CLIENT_LOGIN                 	= 500001,  //登录(返回)
	RES_CONNECT_GATE									= 500002,	//客户端登录gate(返回)
	RES_HEARTBEAT 										= 	500003,	//心跳(返回)
};

enum Client_Game_Message {
	REQ_FETCH_ROLE_INFO								=	120001,	//获取角色信息
	REQ_CREATE_ROLE 									= 	120002,	//创建角色

	REQ_FETCH_BAG_INFO 								= 120100,	//获取背包信息
	REQ_USE_ITEM 											= 120101,	//使用物品
	REQ_SELL_ITEM 										= 120102,	//出售物品

	REQ_FETCH_MAIL_INFO 							= 120200,	//获取邮件信息
	REQ_PICKUP_MAIL 									= 120201,	//收取附件和金钱
	REQ_DEL_MAIL 											= 120202,	//删除邮件
	REQ_SEND_MAIL 										= 120203,	//发送邮件

	REQ_FETCH_HERO_INFO								=	120300,	//获取英雄信息
	REQ_ADD_HERO_STAR									=	120301,	//提高英雄星级
	REQ_ADD_HERO_QUALITY							= 120302,	//提高英雄品质
	REQ_ADD_EQUIP_LEVEL								= 120303,	//提高英雄装备等级
};

enum Game_Client_Message {
	RES_FETCH_ROLE_INFO								=	520001,	//获取角色信息(返回)
	RES_CREATE_ROLE 									= 	520002,	//创建角色(返回)

	RES_FETCH_BAG_INFO 								= 520100,	//获取背包信息(返回)
	RES_USE_ITEM											= 520101,	//使用物品(返回)
	RES_SELL_ITEM 										= 520102,	//出售物品(返回)

	RES_FETCH_MAIL_INFO								= 520200,	//获取邮件信息(返回)
	RES_PICKUP_MAIL 									=	520201,	//收取附件(返回)
	RES_DEL_MAIL 											= 520202,	//删除邮件(返回)
	RES_SEND_MAIL 										= 520203,	//发送邮件(返回)

	RES_FETCH_HERO_INFO								=	520300,	//获取英雄信息(返回)
	RES_ADD_HERO_STAR									=	520301,	//提高英雄星级(返回)
	RES_ADD_HERO_QUALITY							= 520302,	//提高英雄品质(返回)
	RES_ADD_EQUIP_LEVEL								= 520303,	//提高英雄装备等级(返回)
};

//此次包含login,game,chat,master与gate通信的消息
enum Gate_Message {
	SYNC_GATE_LOGIN_PLAYER_ACCOUNT     = 140000,  //gate校验玩家账户、session
	SYNC_LOGIN_GATE_PLAYER_ACCOUNT     = 140001,  //login返回session校验结果
	SYNC_GATE_GAME_PLAYER_SIGNOUT 			= 	140002,	//gate同步玩家掉线到game
};

enum Game_DB_Message {
	SYNC_GAME_DB_LOAD_DB_CACHE					=	150000,	//加载db_cache
	SYNC_GAME_DB_LOAD_PLAYER_INFO			=	150001,	//加载玩家信息
	SYNC_GAME_DB_CREATE_PLAYER					=	150002,	//创建玩家
	SYNC_GAME_DB_SAVE_PLAYER_INFO			= 150003,	//保存玩家信息
	SYNC_GAME_DB_SAVE_MAIL_INFO				= 150004,	//保存邮件信息
};

enum DB_Game_Message {
	SYNC_DB_GAME_LOAD_DB_CACHE					=	550000,	//加载db_cache(返回)
	SYNC_DB_GAME_LOAD_PLAYER_INFO			=	550001,	//加载玩家信息(返回)
	SYNC_DB_GAME_CREATE_PLAYER					=	550002,	//创建玩家(返回)
	SYNC_DB_GAME_SAVE_PLAYER_INFO			=	550003,	//保存玩家信息(返回)
};

enum Game_Master_Message {
	SYNC_GAME_MASTER_PLYAER_SIGNIN			=	160001,	//同步玩家登录消息到master
	SYNC_GAME_MASTER_PLAYER_SIGNOUT		=	160002,	//同步玩家离线消息到master
};

enum LOG_Message {
	SYNC_LOG_TEST_STREAM 							= 180000,	//后台MySQL数据库插入测试
	SYNC_LOG_LOGINOUT_STREAM 					= 180001,	//后台登录退出流水
};

enum Active_Message{
	ACTIVE_DISCONNECT 								=	300000,	//服务器主动断开连接

	ACTIVE_ITEM_INFO 									= 300100,	//物品信息更新
	ACTIVE_ITEM_ADDIT_INFO 						= 300101,	//物品附加信息更新
	ACTIVE_MONEY_INFO 								= 300102,	//金钱更新

	ACTIVE_RECEIVE_MAIL 							= 300200,	//邮件信息更新
};

enum Inner_Message{
	SYNC_INNER_TIMER_TICK 						= 	400000,	//定时器tick
};

#endif /* MSG_MESSAGE_H_ */
