// BOZONNIER Sylvain - CyberA 2028
const Database = require('../core/Database');

class DashboardModel {
  getStats() {
    const books = Database.getFile('books') || [];
    const authors = Database.getFile('authors') || [];
    const borrowed = books.filter(b => b.status === 'emprunté').length;
    return {
      books: books.length,
      authors: authors.length,
      borrowed
    };
  }
}

module.exports = new DashboardModel();
