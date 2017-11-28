// This is an auto generated file created from QB code generator v1.0.0
#ifndef __QB_MKTDATA_FENICSMESSAGE_H
#define __QB_MKTDATA_FENICSMESSAGE_H

#include <unordered_map>
#include <string>
#include <vector>

#include "core/utils/Timestamp.h"
#include "mktdata/msgs/QMessage.h"
#include "mktdata/msgs/Messages.h"

using namespace QB::Core;
using namespace std;

namespace QB { namespace MktData { namespace FENICS {

typedef int64_t time_t;

struct OrderDeleted : public QMessage
{
  int32_t seq_num;
  string symbol;
  int32_t exchange_seq_num;
  time_t source_time;
  uint64_t order_id;
  time_t recvd_time;

  OrderDeleted();
  void clear();

  virtual const char* tableName() const;
  virtual K           to_k(vector<QMessage*>& v) const;
  virtual void        print()     const;
  virtual void        release();
  ostream& operator >> (ostream& os);
};
bool put(IOPacket& p, const OrderDeleted& v);
bool get(IOPacket& p, OrderDeleted& v);
ostream& operator << (ostream& os,
                      const QB::MktData::FENICS::OrderDeleted& obj);

struct OrderExecuted : public QMessage
{
  int32_t seq_num;
  string symbol;
  int32_t exchange_seq_num;
  time_t source_time;
  uint64_t order_id;
  int32_t filled_qty;
  uint64_t trade_id;
  double trade_price;
  time_t recvd_time;

  OrderExecuted();
  void clear();

  virtual const char* tableName() const;
  virtual K           to_k(vector<QMessage*>& v) const;
  virtual void        print()     const;
  virtual void        release();
  ostream& operator >> (ostream& os);
};
bool put(IOPacket& p, const OrderExecuted& v);
bool get(IOPacket& p, OrderExecuted& v);
ostream& operator << (ostream& os,
                      const QB::MktData::FENICS::OrderExecuted& obj);

struct AddOrder : public QMessage
{
  int32_t seq_num;
  string symbol;
  int32_t exchange_seq_num;
  time_t source_time;
  uint64_t order_id;
  string side;
  int32_t qty;
  double price;
  time_t recvd_time;

  AddOrder();
  void clear();

  virtual const char* tableName() const;
  virtual K           to_k(vector<QMessage*>& v) const;
  virtual void        print()     const;
  virtual void        release();
  ostream& operator >> (ostream& os);
};
bool put(IOPacket& p, const AddOrder& v);
bool get(IOPacket& p, AddOrder& v);
ostream& operator << (ostream& os,
                      const QB::MktData::FENICS::AddOrder& obj);

}}} // namespace QB::MktData::Core
#endif