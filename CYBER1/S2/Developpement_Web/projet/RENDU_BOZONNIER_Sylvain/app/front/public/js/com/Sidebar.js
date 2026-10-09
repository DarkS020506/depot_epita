// BOZONNIER Sylvain - CyberA 2028
Import([
  '[html]/com/sidebar.html',
], function (tpl) {

  class Sidebar {
    constructor(element) {
      this.element = element;
      this.element.innerHTML = tpl;

      this.element.querySelectorAll('[data-nav]').forEach(function (item) {
        item.addEventListener('click', function () {
          window.navigate(item.getAttribute('data-nav'));
        });
      });

      var logout = this.element.querySelector('#sidebar-logout');
      if (logout) {
        logout.addEventListener('click', function () {
          sessionStorage.removeItem('auth');
          window.location.href = '/';
        });
      }

      window.addEventListener('navigate', this.updateActive.bind(this));
      this.updateActive();
    }

    updateActive() {
      var current = window.location.pathname;
      this.element.querySelectorAll('[data-nav]').forEach(function (item) {
        var nav = item.getAttribute('data-nav');
        if (nav === '/' ? current === '/' : current.startsWith(nav)) {
          item.classList.add('active');
        } else {
          item.classList.remove('active');
        }
      });
    }
  }

  return Sidebar;
});
