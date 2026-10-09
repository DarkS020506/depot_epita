const BookModel = require('../models/BookModel');

class BookController {
  getBook(query, body) {
    if(query && query.id) {
      const id = parseInt(query.id, 10);
      if(!Number.isNaN(id)) {
        return BookModel.getBookById(id);
      }
    }
    return false;
  }

  postBook(query, body) {
    if (body && body.title && body.authors) {
      return BookModel.createBook(body.title, body.authors);
    }
    return { error: "Missing title or authors" };
  }

  patchBook(query, body) {
    if (query && query.id) {
      const id = parseInt(query.id, 10);

      if (!Number.isNaN(id)) {
        const updated = BookModel.editBook(id, body);

        if (updated) {
          return updated;
        }

        return { error: "Book not found" };
      }
    }

    return { error: "Invalid ID" };
  }
  

  routes = [
    { url: 'api/book/', handler: this.getBook, method: 'GET' },
    { url: 'api/book/', handler: this.postBook, method: 'POST' },
    { url: 'api/book/', handler: this.patchBook, method: 'PUT' },
  ];
}

module.exports = new BookController();