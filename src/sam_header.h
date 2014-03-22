#ifndef __foghorn__sam_header__
#define __foghorn__sam_header__

#include "htslib/sam.h"

namespace foghorn {

class SamHeader {
 public:
  explicit SamHeader();
  // explicit SamHeader(const Sam& record);
  SamHeader(const bam_hdr_t* header);
  SamHeader(const SamHeader& other);
  SamHeader(SamHeader&& other);
  SamHeader& operator=(const SamHeader& other);
  ~SamHeader();

 private:
  bam_hdr_t* m_header;

  friend class SamWriter;
};

}
#endif 