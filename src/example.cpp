// ==========================
// example.cpp
// This is a simple example to show you how to use the SSW C++ library.
// To run this example:
// 1) g++ -Wall ssw_cpp.cpp ssw.c example.cpp
// 2) ./a.out
// Created by Wan-Ping Lee on 09/04/12.
// Last revision by Mengyao Zhao on 2023-Apr-21
// ==========================

#include <algorithm>
#include <iostream>
#include <string>

#include "ssw_cpp.h"

using std::cout;
using std::endl;
using std::string;

static void PrintAlignment(const StripedSmithWaterman::Alignment& alignment);

int main() {
  const string  ref     = "CAGCCTTTCTGACCCGGAAATCAAAATAGGCACAACAAA";
  const string  query   = "CTGAGCCGGTAAATC";
  const int32_t maskLen = std::max(query.size() / 2, size_t(15));

  // Declares a default Aligner
  StripedSmithWaterman::Aligner aligner;
  // Declares a default filter
  StripedSmithWaterman::Filter filter;
  // Declares an alignment that stores the result
  StripedSmithWaterman::Alignment alignment;
  // Aligns the query to the ref
  aligner.Align(query.c_str(), query.size(), ref.c_str(), ref.size(), filter, alignment, maskLen);

  PrintAlignment(alignment);

  return 0;
}

static void PrintAlignment(const StripedSmithWaterman::Alignment& alignment) {
  cout << "===== SSW result =====" << endl;
  cout << "Best Smith-Waterman score:\t" << alignment.sw_score << endl
       << "Next-best Smith-Waterman score:\t" << alignment.sw_score_next_best << endl
       << "Reference start:\t" << alignment.ref_begin << endl
       << "Reference end:\t" << alignment.ref_end << endl
       << "Query start:\t" << alignment.query_begin << endl
       << "Query end:\t" << alignment.query_end << endl
       << "Next-best reference end:\t" << alignment.ref_end_next_best << endl
       << "Number of mismatches:\t" << alignment.mismatches << endl
       << "Cigar: " << alignment.cigar_string << endl;
  cout << "======================" << endl;
}
