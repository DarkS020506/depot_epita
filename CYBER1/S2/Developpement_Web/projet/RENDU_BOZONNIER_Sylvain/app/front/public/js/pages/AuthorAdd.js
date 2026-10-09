// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/author-add.html',
], function (tpl) {

  class AuthorAdd {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;

      this.nameInput = this.element.querySelector('#author-name');
      this.submitBtn = this.element.querySelector('#submit-btn');
      this.message = this.element.querySelector('#form-message');

      this.submitBtn.addEventListener('click', this.onSubmit.bind(this));
    }

    async onSubmit() {
      var name = this.nameInput.value.trim();

      if (!name) {
        this.showMessage('Veuillez saisir un nom.', false);
        return;
      }

      try {
        var res = await fetch('/api/author/', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ name: name })
        });
        var data = await res.json();
        if (data.data && data.data.id !== undefined) {
          this.showMessage('Auteur ajouté avec succès.', true);
          this.nameInput.value = '';
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

  return AuthorAdd;
});
