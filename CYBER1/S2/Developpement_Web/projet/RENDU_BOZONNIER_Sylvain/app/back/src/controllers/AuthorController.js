// BOZONNIER Sylvain - CyberA 2028
const AuthorModel = require('../models/AuthorModel');

class AuthorController {
  getAuthors(query, body) {
    const name = query && query.name ? query.name : null;
    const authors = AuthorModel.searchAuthors(name);
    const counts = AuthorModel.getBookCountByAuthor();
    return authors.map(a => ({ ...a, bookCount: counts[a.id] || 0 }));
  }

  getAuthor(query, body) {
    if (query && query.id !== undefined) {
      const id = parseInt(query.id, 10);
      if (!Number.isNaN(id)) {
        return AuthorModel.getAuthorById(id);
      }
    }
    return false;
  }

  postAuthor(query, body) {
    const { name } = body;
    if (!name) return false;
    const id = AuthorModel.createAuthor(name);
    return { id };
  }

  patchAuthor(query, body) {
    if (!query || query.id === undefined) return false;
    const id = parseInt(query.id, 10);
    if (Number.isNaN(id)) return false;
    return AuthorModel.editAuthor(id, body);
  }
}

module.exports = new AuthorController();
