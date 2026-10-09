// BOZONNIER Sylvain - CyberA 2028
const Database = require('../core/Database');

class BookModel {
  getAllBooks() {
    return Database.getFile('books') || [];
  }

  getBookById(id) {
    return Database.get('books', id);
  }

  searchBooks(name, authorId) {
    let books = this.getAllBooks();
    if (name) {
      const lower = name.toLowerCase();
      books = books.filter(b => b.title.toLowerCase().includes(lower));
    }
    if (authorId !== undefined && !isNaN(authorId)) {
      books = books.filter(b => b.authorId === authorId);
    }
    return books;
  }

  createBook(title, authorId, status) {
    const file = Database.getFile('books') || [];
    const id = file.length;
    Database.edit('books', id, { id, title, authorId, status: status || 'en stock' });
    return id;
  }

  editBook(id, book) {
    const oldBook = Database.get('books', id);
    if (oldBook) {
      Database.edit('books', id, { ...oldBook, ...book });
      return Database.get('books', id);
    }
    return false;
  }
}

module.exports = new BookModel();
