// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/author-search.html',
], function (tpl) {

  class AuthorSearch {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;

      this.searchInput = this.element.querySelector('#search-input');
      this.filterBtn = this.element.querySelector('#filter-btn');
      this.tbody = this.element.querySelector('#authors-body');

      this.filterBtn.addEventListener('click', this.onFilter.bind(this));
      this.searchInput.addEventListener('keydown', function (e) {
        if (e.key === 'Enter') this.onFilter();
      }.bind(this));

      this.loadAuthors('');
    }

    async loadAuthors(name) {
      var url = '/api/authors/';
      if (name) url += '?name=' + encodeURIComponent(name);
      try {
        var res = await fetch(url);
        var data = await res.json();
        this.renderRows(data.data || []);
      } catch (err) {
        console.error('Erreur chargement auteurs', err);
      }
    }

    renderRows(authors) {
      var self = this;
      this.tbody.innerHTML = '';
      authors.forEach(function (author) {
        var tr = document.createElement('tr');
        tr.innerHTML =
          '<td><span class="table-link">' + self.escape(author.name) + '</span></td>' +
          '<td class="col-right">' + (author.bookCount || 0) + '</td>';
        tr.querySelector('.table-link').addEventListener('click', function () {
          window.navigate('/author/' + author.id);
        });
        self.tbody.appendChild(tr);
      });
    }

    onFilter() {
      this.loadAuthors(this.searchInput.value.trim());
    }

    escape(str) {
      return String(str)
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;');
    }
  }

  return AuthorSearch;
});
