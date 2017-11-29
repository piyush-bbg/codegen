#ifndef QB_CODEGEN_MESSAGE_HPP
#define QB_CODEGEN_MESSAGE_HPP

// Additional includes
#include "core/utils/Timestamp.h"
#include "mktdata/msgs/Messages.h"
#include "mktdata/msgs/QMessage.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <stdint.h>

using namespace QB::Core;
using namespace std;

namespace QB {
namespace MktData {
namespace FENICS {

/*  
 * typedefs.
 */
typedef int64_t time_t;

struct AddOrder : public QMessage
{
  int32_t seq_num;
  string symbol;
  int32_t exchange_seq_num;
  time_t source_time;
  int64_t order_id;
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

} // namespace FENICS
} // namespace MktData
} // namespace QB
#endif