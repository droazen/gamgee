#ifndef __gamgee_variant_writer__
#define __gamgee_variant_writer__

#include <string>

#include "variant.h"
#include "variant_header.h"
#include "htslib/vcf.h"

namespace gamgee {

/**
 * @brief utility class to write out a SAM/BAM/CRAM file to any stream
 * @todo add serialization option
 */
class VariantWriter {

 public: 

  /**
   * @brief Creates a new VariantWriter using the specified output file name
   * @param output_fname file to write to. The default is stdout (as defined by htslib)
   * @param binary whether the output should be in BAM (true) or SAM format (false) 
   * @note the header is copied and managed internally
   */
  explicit VariantWriter(const std::string& output_fname = "-", const bool binary = true);

  /**
   * @brief Creates a new VariantWriter with the header extracted from a Variant record and using the specified output file name
   * @param header       VariantHeader object to make a copy from
   * @param output_fname file to write to. The default is stdout  (as defined by htslib)
   * @param binary whether the output should be in BAM (true) or SAM format (false) 
   * @note the header is copied and managed internally
   */
  explicit VariantWriter(const VariantHeader& header, const std::string& output_fname = "-", const bool binary = true);

  /**
   * @brief takes care of closing the file/stream
   */
  ~VariantWriter();

  /**
   * @brief Adds a record to the file stream
   * @param body the record
   */
  void add_record(const VariantBody& body);

  /**
   * @brief Adds a header to the file stream.
   * @param header the header
   * @note the header is a requirement to add records
   */
  void add_header(const VariantHeader& header);

 private:
  htsFile* m_out_file;    ///< the file or stream to write out to ("-" means stdout)
  VariantHeader m_header; ///< holds a copy of the header throughout the production of the output (necessary for every record that gets added)

  static htsFile* open_file(const std::string& output_fname, const std::string& binary);
  void write_header() const;

};

}
#endif 
