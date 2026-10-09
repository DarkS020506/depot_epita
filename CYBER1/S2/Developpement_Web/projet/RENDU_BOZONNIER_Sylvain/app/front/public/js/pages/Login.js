// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/pages/login.html',
], function (tpl) {

  class Login {
    constructor(element, onSuccess) {
      this.element = element;
      this.onSuccess = onSuccess;
      this.element.innerHTML = tpl;

      var form = this.element.querySelector('#login-form');
      form.addEventListener('submit', this.onSubmit.bind(this));
    }

    async onSubmit(e) {
      e.preventDefault();
      var login = this.element.querySelector('[name="login"]').value;
      var password = this.element.querySelector('[name="password"]').value;
      var errEl = this.element.querySelector('#login-error');

      try {
        var res = await fetch('/api/auth/', {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body: JSON.stringify({ login: login, password: password })
        });
        var data = await res.json();
        if (data.data && data.data.success) {
          this.onSuccess();
        } else {
          errEl.textContent = 'Identifiant ou mot de passe incorrect.';
        }
      } catch (err) {
        errEl.textContent = 'Erreur de connexion au serveur.';
      }
    }
  }

  return Login;
});
