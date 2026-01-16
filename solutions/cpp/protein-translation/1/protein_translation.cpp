#include "protein_translation.h"
#include <string>
#include <map>
#include <vector>

namespace protein_translation {

    std::vector<std::string> get_codons(std::string rna){
        std::vector<std::string> codons;
        for(size_t i = 0; i < rna.size(); i += 3){
               codons.push_back(rna.substr(i, 3));
        }
        return codons;
    }
    std::vector<std::string> proteins(std::string rna){
    const std::map<std::string, std::vector<std::string>> protein_to_codon = {
            {"Methionine", {"AUG"}},
            {"Phenylalanine", {"UUU", "UUC"}},
            {"Leucine", {"UUA", "UUG"}},
            {"Serine", {"UCU", "UCC", "UCA", "UCG"}},
            {"Tyrosine", {"UAU", "UAC"}},
            {"Cysteine", {"UGU", "UGC"}},
            {"Tryptophan", {"UGG"}},
            {"STOP", {"UAA", "UAG", "UGA"}}
        };
        std::vector<std::string>  result;
        std::vector<std::string> codons = get_codons(rna);
        for(auto i: codons){
            for(auto [protein, codon]: protein_to_codon){
                for(auto c: codon){
                    if(c == i){
                        if(protein == "STOP"){
                            return result;
                        }
                        result.push_back(protein);
                        break;
                    }
                }
            }
        }

        return result;
    }
}  // namespace protein_translation
