#pragma once
#include <string>

struct	s_commands;

std::string msg_welcome(const std::string& nick);
std::string msg_yourhost(const std::string& nick);
std::string msg_created(const std::string& nick);
std::string msg_svrinfo(const std::string& nick);
std::string msg_err_needmoreparams(const std::string& cmd);
std::string msg_err_passwdmismatch();
std::string msg_err_nicknameinuse(const std::string& nick);
std::string msg_err_notregistered();
std::string msg_err_unknowncommand(const std::string& cmd);
std::string msg_err_nosuchchannel(const std::string& nick, const std::string& channel);
std::string msg_err_notonchannel(const std::string& nick, const std::string& channel);
std::string msg_err_usernotinchannel(const std::string nick, const std::string& user, const std::string& channel);
std::string msg_err_channelisfull(const std::string& nick, const std::string& channel);
std::string msg_err_chanoprivsneeded(const std::string& nick, const std::string& channel, const std::string& message);
std::string msg_err_erroneusnickname(const std::string& nick);
std::string msg_err_alreadyregistered(const std::string& nick);
std::string msg_notice(const std::string& text);
std::string	msg_error(const std::string &message, int error_code, s_commands& com);
void	callCmdMsg(const std::string &message, int error, s_commands& com, std::string &buffer);
std::string my_notice_info(const std::string& nickname, const std::string& message);
std::string my_notice_error(const std::string& nickname, const std::string& message);
std::string     my_kick_message(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& message, const std::string& target, const std::string& channel);
std::string     my_invite_message(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& target, const std::string& channel);
std::string     my_topic_message(const std::string& nickname, const std::string& username, const std::string& hostname,  const std::string& channel, const std::string& topic);
std::string     my_privmsg_message(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& target, const std::string& message);
std::string     my_join_message(const std::string& nickname, const std::string& username, const std::string& hostname, const std::string& channel);
std::string     my_join_rpl_topic(const std::string& nickname, const std::string& channel, const std::string& topic);
std::string     my_join_rpl_topic_whotime(const std::string& nick, const std::string& nick2, const std::string& user, const std::string& host, const std::string& channel, std::string& timestamp);
std::string     my_join_rpl_namreply(const std::string &nick, const std::string& channel);
std::string     my_join_rpl_endofnames(const std::string &nick, const std::string &channel);
std::string     my_part_message(const std::string& nick, const std::string& user, const std::string& host, const std::string& channel,  const std::string& message);
std::string     my_topic_operator_error(const std::string& nick, const std::string& channel, const std::string& message);
std::string     my_useronchannel(const std::string& owner, const std::string& nick, const std::string& channel, const std::string& message);
std::string     my_notonchannel(const std::string& nick, const std::string& channel, const std::string& message);
std::string     my_nosuchnickchannel(const std::string& nick, const std::string& forget,const std::string& channel, const std::string& message);
std::string     my_usernotinchannel(std::string& nick, const std::string& target, const std::string& channel, const std::string& message);
