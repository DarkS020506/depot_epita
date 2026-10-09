// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/dashboard.html',
], function (tpl) {

  class Dashboard {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;
      this.load();
    }

    async load() {
      try {
        var res = await fetch('/api/dashboard/');
        var data = await res.json();
        if (data.data) {
          this.element.querySelector('#stat-books').textContent = data.data.books;
          this.element.querySelector('#stat-authors').textContent = data.data.authors;
          this.element.querySelector('#stat-borrowed').textContent = data.data.borrowed;
        }
      } catch (err) {
        console.error('Erreur chargement dashboard', err);
      }
    }
  }

  return Dashboard;
});
