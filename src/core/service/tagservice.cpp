#include "service/tagservice.hpp"


Service *TagService::handler() {
    _tagView.printMenu();
    int response = std::stoi(_tagView.getInput());

    switch (response) {
        case 0:
            return listTags();
        case 1:
            return addTag();
        case 2:
            return updateTag();
    }

    return nullptr;
}

Service *TagService::listTags() {
    std::vector<Tag> tags = _tagRepo.getAllTags();
    _tagView.printTags(tags);
    return new TagService(_user);
}

Service *TagService::addTag() {
    _tagView.displayMessage("Digite o nome da tag: ");
    std::string tagname = _tagView.getInput();
    if (_tagRepo.getTagByName(tagname) == nullptr) {
        _tagRepo.createTag(tagname);
        _tagView.displayMessage("Tag adicionada\n");

    } else {
        _tagView.displayMessage("Tag já existente\n");
    }
    return new TagService(_user);
}

Service *TagService::updateTag() {
    std::vector<std::string> response = _tagView.renderUpdateForm();
    Tag *oldTag = _tagRepo.getTagByName(response.at(0));
    if (oldTag == nullptr) {
        _tagView.displayMessage("Tag não existe\n");
    } else if(_tagRepo.getTagByName(response.at(1)) != nullptr) {
        _tagView.displayMessage("Tag com o nome desejado ja existe\n");
    } else {
        Tag *newTag = _tagRepo.updateTag(*oldTag, response.at(1));
        delete oldTag;
        _tagView.displayMessage("Nome de tag alterado com sucesso\n");

    }

    return new TagService(_user);
}