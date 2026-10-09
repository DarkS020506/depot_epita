// BOZONNIER Sylvain - CyberA 2028
Import([
  '[js]/com/Sidebar.js',
  '[html]/layout.html',
  '[js]/pages/Home.js',
  '[js]/pages/Login.js',
  '[js]/pages/Dashboard.js',
  '[js]/pages/BookSearch.js',
  '[js]/pages/AuthorSearch.js',
  '[js]/pages/BookAdd.js',
  '[js]/pages/AuthorAdd.js',
  '[js]/pages/BookEdit.js',
  '[js]/pages/AuthorEdit.js',
  '[js]/pages/NotFound.js',
], function (Sidebar, layoutTpl, Home, Login, Dashboard, BookSearch, AuthorSearch, BookAdd, AuthorAdd, BookEdit, AuthorEdit, NotFound) {

  var root = document.getElementById('root');

  function isLoggedIn() {
    return sessionStorage.getItem('auth') === 'true';
  }

  function showApp() {
    root.innerHTML = layoutTpl;
    var sidebarNode = document.getElementById('sidebar');
    new Sidebar(sidebarNode);

    window.addEventListener('popstate', function () {
      renderPage(window.location.pathname);
    });

    renderPage(window.location.pathname);
  }

  window.navigate = function (path) {
    history.pushState({}, '', path);
    window.dispatchEvent(new Event('navigate'));
    renderPage(path);
  };

  function renderPage(pathname) {
    var main = document.getElementById('main');
    var rootEl = document.getElementById('root');
    
    if (!isLoggedIn() && pathname !== '/' && pathname !== '' && pathname !== '/login') {
      window.navigate('/');
      return;
    }
    
    if (!main) {
      if (pathname === '/login') {
        new Login(rootEl, function () {
          sessionStorage.setItem('auth', 'true');
          showApp();
          window.navigate('/');
        });
      } else {
        new Home(rootEl);
      }
      return;
    }
    
    main.innerHTML = '';

    var parts = pathname.split('/').filter(function (p) { return p !== ''; });

    if (pathname === '/login') {
      if (isLoggedIn()) {
        window.navigate('/');
      } else {
        new Login(main, function () {
          sessionStorage.setItem('auth', 'true');
          showApp();
          window.navigate('/');
        });
      }
    } else if (pathname === '/' || pathname === '') {
      if (isLoggedIn()) {
        new Dashboard(main);
      } else {
        new Home(main);
      }
    } else if (pathname === '/books') {
      new BookSearch(main);
    } else if (pathname === '/authors') {
      new AuthorSearch(main);
    } else if (pathname === '/book/add') {
      new BookAdd(main);
    } else if (pathname === '/author/add') {
      new AuthorAdd(main);
    } else if (parts.length === 2 && parts[0] === 'book') {
      var bookId = parseInt(parts[1], 10);
      if (!isNaN(bookId)) {
        new BookEdit(main, bookId);
      } else {
        new NotFound(main);
      }
    } else if (parts.length === 2 && parts[0] === 'author') {
      var authorId = parseInt(parts[1], 10);
      if (!isNaN(authorId)) {
        new AuthorEdit(main, authorId);
      } else {
        new NotFound(main);
      }
    } else {
      new NotFound(main);
    }
  }

  if (isLoggedIn()) {
    showApp();
  } else {
    new Home(root);
  }

});
