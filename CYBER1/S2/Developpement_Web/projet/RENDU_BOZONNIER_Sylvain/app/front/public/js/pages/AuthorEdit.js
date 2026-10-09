// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/author-edit.html',
], function (tpl) {

  class AuthorEdit {
    constructor(element, authorId) {
      this.element = element;
      this.authorId = authorId;
      this.element.innerHTML = tpl;

      this.nameInput = this.element.querySelector('#author-name');
      this.submitBtn = this.element.querySelector('#submit-btn');
      this.message = this.element.querySelector('#form-message');
      this.booksBody = this.element.querySelector('#author-books-body');

      this.submitBtn.addEventListener('click', this.onSubmit.bind(this));
      this.load();
    }

    async load() {
      try {
        var authorRes = await fetch('/api/author/?id=' + this.authorId);
        var authorData = await authorRes.json();
        if (authorData.data) {
          this.nameInput.value = authorData.data.name || '';
        }

        var booksRes = await fetch('/api/books/?authorId=' + this.authorId);
        var booksData = await booksRes.json();
        this.renderBooks(booksData.data || []);
      } catch (err) {
        console.error('Erreur chargement auteur', err);
      }
    }

    renderBooks(books) {
      var self = this;
      this.booksBody.innerHTML = '';
      if (books.length === 0) {
        var tr = document.createElement('tr');
        tr.innerHTML = '<td colspan="2" style="color:#999;font-style:italic;">Aucun livre</td>';
        this.booksBody.appendChild(tr);
        return;
      }
      books.forEach(function (book) {
        var tr = document.createElement('tr');
        var statusClass = book.status === 'emprunté' ? 'status-borrowed' : 'status-stock';
        tr.innerHTML =
          '<td><span class="table-link">' + self.escape(book.title) + '</span></td>' +
          '<td class="' + statusClass + '">' + self.escape(book.status) + '</td>';
        tr.querySelector('.table-link').addEventListener('click', function () {
          window.navigate('/book/' + book.id);
        });
        self.booksBody.appendChild(tr);
      });
    }

    async onSubmit() {
      var name = this.nameInput.value.trim();
      if (!name) {
        this.showMessage('Veuillez saisir un nom.', false);
        return;
      }

      try {
        var res = await fetch('/api/author/?id=' + this.authorId, {
          method: 'PUT',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ name: name })
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

    escape(str) {
      return String(str)
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;');
    }
  }

  return AuthorEdit;
});
