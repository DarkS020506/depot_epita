// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/book-edit.html',
], function (tpl) {

  class BookEdit {
    constructor(element, bookId) {
      this.element = element;
      this.bookId = bookId;
      this.element.innerHTML = tpl;

      this.titleInput = this.element.querySelector('#book-title');
      this.authorSelect = this.element.querySelector('#book-author');
      this.statusSelect = this.element.querySelector('#book-status');
      this.submitBtn = this.element.querySelector('#submit-btn');
      this.message = this.element.querySelector('#form-message');

      this.submitBtn.addEventListener('click', this.onSubmit.bind(this));
      this.load();
    }

    async load() {
      try {
        var authorsRes = await fetch('/api/authors/');
        var authorsData = await authorsRes.json();
        var authors = authorsData.data || [];

        var select = this.authorSelect;
        authors.forEach(function (a) {
          var opt = document.createElement('option');
          opt.value = a.id;
          opt.textContent = a.name;
          select.appendChild(opt);
        });

        var bookRes = await fetch('/api/book/?id=' + this.bookId);
        var bookData = await bookRes.json();
        var book = bookData.data;

        if (book) {
          this.titleInput.value = book.title || '';
          this.authorSelect.value = book.authorId !== undefined ? String(book.authorId) : '';
          this.statusSelect.value = book.status || '';
        }
      } catch (err) {
        console.error('Erreur chargement livre', err);
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
        var res = await fetch('/api/book/?id=' + this.bookId, {
          method: 'PUT',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ title: title, authorId: authorId, status: status })
        });
        var data = await res.json();
        if (data.data) {
          this.showMessage('Modifications enregistrées.', true);
        } else {
          this.showMessage('Erreur lors de la sauvegarde.', false);
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

  return BookEdit;
});
