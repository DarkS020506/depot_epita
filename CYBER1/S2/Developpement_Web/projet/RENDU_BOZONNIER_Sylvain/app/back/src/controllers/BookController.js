// BOZONNIER Sylvain - CyberA 2028
const BookModel = require('../models/BookModel');
const AuthorModel = require('../models/AuthorModel');

class BookController {
  getBooks(query, body) {
    const name = query && query.name ? query.name : null;
    const authorId = query && query.authorId !== undefined ? parseInt(query.authorId, 10) : undefined;
    const books = BookModel.searchBooks(name, authorId);
    const authors = AuthorModel.getAllAuthors();
    return books.map(b => {
      const author = authors.find(a => a.id === b.authorId);
      return { ...b, authorName: author ? author.name : 'Inconnu' };
    });
  }

  getBook(query, body) {
    if (query && query.id !== undefined) {
      const id = parseInt(query.id, 10);
      if (!Number.isNaN(id)) {
        const book = BookModel.getBookById(id);
        if (book) {
          const author = AuthorModel.getAuthorById(book.authorId);
          return { ...book, authorName: author ? author.name : '' };
        }
      }
    }
    return false;
  }

  postBook(query, body) {
    const { title, authorId, status } = body;
    if (!title) return false;
    const parsedAuthorId = authorId !== undefined ? parseInt(authorId, 10) : undefined;
    const id = BookModel.createBook(title, parsedAuthorId, status);
    return { id };
  }

  patchBook(query, body) {
    if (!query || query.id === undefined) return false;
    const id = parseInt(query.id, 10);
    if (Number.isNaN(id)) return false;
    const data = { ...body };
    if (data.authorId !== undefined) data.authorId = parseInt(data.authorId, 10);
    return BookModel.editBook(id, data);
  }
}

module.exports = new BookController();
