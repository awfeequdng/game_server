/*
 *  Created on: Dec 16, 2015
 *      Author: zhangyalei
 */


#ifndef GAME_PLAYER_H_
#define GAME_PLAYER_H_

#include "Public_Struct.h"
#include "Bag.h"

class Game_Player {
public:
	const static Time_Value game_player_save_interval_;

	Game_Player(void);
	virtual ~Game_Player(void);

	void set_cid_info(Cid_Info &cid_info);
	Cid_Info &cid_info(void);

	int respond_success_result(int msg_id, Block_Buffer *buf = 0);
	int respond_error_result(int msg_id, int err, Block_Buffer *buf = 0);

	Player_Data const &player_data(void) const { return player_data_; }
	Block_Buffer *player_data_buffer(void) { return player_data_buffer_; }
	Game_Player_Info const &game_player_info(void) const { return player_data_.game_player_info; }
	Mail_Info &mail_info(void) { return player_data_.mail_info; }
	Bag& bag(void) { return bag_; }

	int load_player(Player_Data &player_data);
	int save_player(bool is_logout = false);

	int sign_in(std::string account);
	int sign_out(void);
	void reset(void);

	int sync_signin_to_master(void);
	int sync_signout_to_master(void);

	int tick(Time_Value &now);
	int link_close(void);
	void set_recycle(void);
	int recycle_status(void);
	int recycle_tick(const Time_Value &now);

	int register_timer(void);
	int unregister_timer(void);

	int login_success(void);
	int respond_role_login(void);

  //发送邮件
  int send_mail(role_id_t receiver_id, Mail_Detail &mail_detail);

private:
	bool is_register_timer_;
	Cid_Info cid_info_;		///登录信息，包括gate_cid和player_cid
	Player_Data player_data_;
	Block_Buffer *player_data_buffer_;
	Recycle_Tick recycle_tick_;
	Time_Value last_save_timestamp_;

	Bag bag_;
};

////////////////////////////////////////////////////////////////////////////////
inline void Game_Player::set_cid_info(Cid_Info &cid_info) {
	cid_info_ = cid_info;
}

inline Cid_Info &Game_Player::cid_info(void) {
	return cid_info_;
}

#endif /* GAME_PLAYER_H_ */
