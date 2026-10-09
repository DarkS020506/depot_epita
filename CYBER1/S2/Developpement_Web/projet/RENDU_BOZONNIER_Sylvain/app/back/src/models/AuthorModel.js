// BOZONNIER Sylvain - CyberA 2028
const Database = require('../core/Database');

class AuthorModel {
  getAllAuthors() {
    return Database.getFile('authors') || [];
  }

  getAuthorById(id) {
    return Database.get('authors', id);
  }

  searchAuthors(name) {
    const authors = this.getAllAuthors();
    if (!name) return authors;
    const lower = name.toLowerCase();
    return authors.filter(a => a.name.toLowerCase().includes(lower));
  }

  createAuthor(name) {
    const file = Database.getFile('authors') || [];
    const id = file.length;
    Database.edit('authors', id, { id, name });
    return id;
  }

  editAuthor(id, data) {
    const old = Database.get('authors', id);
    if (old) {
      Database.edit('authors', id, { ...old, ...data });
      return Database.get('authors', id);
    }
    return false;
  }

  getBookCountByAuthor() {
    const books = Database.getFile('books') || [];
    const counts = {};
    books.forEach(b => {
      const aid = b.authorId;
      if (aid !== undefined) {
        counts[aid] = (counts[aid] || 0) + 1;
      }
    });
    return counts;
  }
}

module.exports = new AuthorModel();
