#include "mktdata/msgs/FENICSMessage.h"

#include "commonlibs/core/utils/Defines.h"
#include "commonlibs/core/utils/ObjectStore.h"
#include "mktdata/include/qb_knk.h"
#include "externaldeps/kdb/include/k.h"

#include <time.h>

using namespace std;
using namespace QB::MktData::FENICS;

#define SET_NULL(v) v = qb_null<decltype(v)>::value
#define STR_NULL(v) v = ""
#define KSTR(x)  sn(const_cast<S>(x.c_str()), x.size())
#define KTIME(t) (t - 10957LL*86400LL*1000000000LL)
#define KINT(v)  (is_qb_null(v) ? ni : v)
#define KDBL(v)  (is_qb_null(v) ? nf : v)
#define KLONG(v) (is_qb_null(v) ? nj : v)

AddOrder::AddOrder()
{
  clear();
}

void AddOrder::clear()
{
   SET_NULL(seq_num);
   STR_NULL(symbol);
   SET_NULL(exchange_seq_num);
   SET_NULL(source_time);
   SET_NULL(order_id);
   STR_NULL(side);
   SET_NULL(qty);
   SET_NULL(price);
   SET_NULL(recvd_time);
}

K AddOrder::to_k(vector<QMessage*>& v) const
{
  int size = (int) v.size();
  K x = qb_knk(
               ktn(KI, size),
               ktn(KS, size),
               ktn(KI, size),
               ktn(KP, size),
               ktn(KJ, size),
               ktn(KS, size),
               ktn(KI, size),
               ktn(KF, size),
               ktn(KP, size)
             );

  for (int i = 0; i < size; i++)
    {
      FENICS::AddOrder* q = (FENICS::AddOrder*)v[i];

      kI(xK[0])[i] = KINT(q->seq_num);
      kS(xK[1])[i] = KSTR(q->symbol);
      kI(xK[2])[i] = KINT(q->exchange_seq_num);
      kJ(xK[3])[i] = KTIME(q->source_time);
      kJ(xK[4])[i] = KLONG(q->order_id);
      kS(xK[5])[i] = KSTR(q->side);
      kI(xK[6])[i] = KINT(q->qty);
      kF(xK[7])[i] = KDBL(q->price);
      kJ(xK[8])[i] = KTIME(q->recvd_time);
    }
  return x;
}

void AddOrder::print() const
{
  LOG_INFO(tableName()<<": "
           << seq_num << ", "
           << symbol << ", "
           << exchange_seq_num << ", "
           << source_time << ", "
           << order_id << ", "
           << side << ", "
           << qty << ", "
           << price << ", "
           << recvd_time
           ) ;
}

ostream& AddOrder::operator >> (ostream& os)
{
  os<<"tablename: "<<tableName()<<"addord";
  return os;
}

void AddOrder::release()
{
  clear();
  Core::ObjectStore::release(this);
}

bool QB::MktData::FENICS::put(QB::Core::IOPacket& p, const AddOrder& v)
{
  bool ret = true;

  ret&=put(p,v.seq_num);
  ret&=put(p,v.symbol);
  ret&=put(p,v.exchange_seq_num);
  ret&=put(p,v.source_time);
  ret&=put(p,v.order_id);
  ret&=put(p,v.side);
  ret&=put(p,v.qty);
  ret&=put(p,v.price);
  ret&=put(p,v.recvd_time);

  return ret;
}

bool QB::MktData::FENICS::get(QB::Core::IOPacket& p, AddOrder& v)
{
  bool ret = true;

  ret&=get(p,v.seq_num);
  ret&=get(p,v.symbol);
  ret&=get(p,v.exchange_seq_num);
  ret&=get(p,v.source_time);
  ret&=get(p,v.order_id);
  ret&=get(p,v.side);
  ret&=get(p,v.qty);
  ret&=get(p,v.price);
  ret&=get(p,v.recvd_time);

  return ret;
}

