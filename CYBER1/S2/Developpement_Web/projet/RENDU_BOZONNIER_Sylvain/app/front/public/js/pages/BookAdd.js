// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/book-add.html',
], function (tpl) {

  class BookAdd {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;

      this.titleInput = this.element.querySelector('#book-title');
      this.authorSelect = this.element.querySelector('#book-author');
      this.statusSelect = this.element.querySelector('#book-status');
      this.submitBtn = this.element.querySelector('#submit-btn');
      this.message = this.element.querySelector('#form-message');

      this.submitBtn.addEventListener('click', this.onSubmit.bind(this));
      this.loadAuthors();
    }

    async loadAuthors() {
      try {
        var res = await fetch('/api/authors/');
        var data = await res.json();
        var authors = data.data || [];
        var select = this.authorSelect;
        authors.forEach(function (a) {
          var opt = document.createElement('option');
          opt.value = a.id;
          opt.textContent = a.name;
          select.appendChild(opt);
        });
      } catch (err) {
        console.error('Erreur chargement auteurs', err);
      }
    }

    async onSubmit() {
      var title = this.titleInput.value.trim();
      var authorId = this.authorSelect.value;
      var status = this.statusSelect.value;

      if (!title || !authorId || !status) {
        this.showMessage('Veuillez remplir tous les champs.', false);
        return;
      }

      try {
        var res = await fetch('/api/book/', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ title: title, authorId: authorId, status: status })
        });
        var data = await res.json();
        if (data.data && data.data.id !== undefined) {
          this.showMessage('Livre ajouté avec succès.', true);
          this.titleInput.value = '';
          this.authorSelect.selectedIndex = 0;
          this.statusSelect.selectedIndex = 0;
        } else {
          this.showMessage('Erreur lors de l\'ajout.', false);
        }
      } catch (err) {
        this.showMessage('Erreur serveur.', false);
      }
    }

    showMessage(text, success) {
      this.message.textContent = text;
      this.message.className = success ? 'form-success' : 'form-error';
    }
  }

  return BookAdd;
});
