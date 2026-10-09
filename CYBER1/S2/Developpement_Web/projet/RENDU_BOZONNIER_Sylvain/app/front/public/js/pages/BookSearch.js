// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/book-search.html',
], function (tpl) {

  class BookSearch {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;

      this.searchInput = this.element.querySelector('#search-input');
      this.filterBtn = this.element.querySelector('#filter-btn');
      this.tbody = this.element.querySelector('#books-body');

      this.filterBtn.addEventListener('click', this.onFilter.bind(this));
      this.searchInput.addEventListener('keydown', function (e) {
        if (e.key === 'Enter') this.onFilter();
      }.bind(this));

      this.loadBooks('');
    }

    async loadBooks(name) {
      var url = '/api/books/';
      if (name) url += '?name=' + encodeURIComponent(name);
      try {
        var res = await fetch(url);
        var data = await res.json();
        this.renderRows(data.data || []);
      } catch (err) {
        console.error('Erreur chargement livres', err);
      }
    }

    renderRows(books) {
      var self = this;
      this.tbody.innerHTML = '';
      books.forEach(function (book) {
        var tr = document.createElement('tr');
        var statusClass = book.status === 'emprunté' ? 'status-borrowed' : 'status-stock';
        tr.innerHTML =
          '<td><span class="table-link">' + self.escape(book.title) + '</span></td>' +
          '<td>' + self.escape(book.authorName || '') + '</td>' +
          '<td class="' + statusClass + '">' + self.escape(book.status) + '</td>';
        tr.querySelector('.table-link').addEventListener('click', function () {
          window.navigate('/book/' + book.id);
        });
        self.tbody.appendChild(tr);
      });
    }

    onFilter() {
      this.loadBooks(this.searchInput.value.trim());
    }

    escape(str) {
      return String(str)
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;');
    }
  }

  return BookSearch;
});
