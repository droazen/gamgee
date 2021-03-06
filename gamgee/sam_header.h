#ifndef __gamgee__sam_header__
#define __gamgee__sam_header__

#include "htslib/sam.h"

#include <memory>

namespace gamgee {

/**
 * @brief Utility class to hold the header of a sam file
 */
class SamHeader {
 public:
  explicit SamHeader();
  explicit SamHeader(const std::shared_ptr<bam_hdr_t>& header);
  SamHeader(const SamHeader& other);
  SamHeader(SamHeader&& other) noexcept;
  SamHeader& operator=(const SamHeader& other);
  SamHeader& operator=(SamHeader&& other) noexcept;
  ~SamHeader() = default; ///< Default destruction is sufficient, since our shared_ptr will handle deallocation

 private:
  std::shared_ptr<bam_hdr_t> m_header;

  friend class SamWriter;
};

}
#endif 
