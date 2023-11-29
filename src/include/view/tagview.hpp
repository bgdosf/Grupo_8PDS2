#include "view/abstractview.hpp"

#include "model/tag.hpp"

#include <string>
#include <vector>

class TagView: public View {
public:
    /// @brief printa o menu inicial
    void printMenu();


    /// @brief printa uma serie de tags
    /// @param tags 
    void printTags(std::vector<Tag> tags);

    /// @brief printa uma unica tag
    /// @param t 
    void printTag(Tag t);

    /// @brief renderiza um formulario de atualizacao de tag
    /// @return um vetor contendo a string do antigo e do novo nome
    std::vector<std::string> renderUpdateForm();

};