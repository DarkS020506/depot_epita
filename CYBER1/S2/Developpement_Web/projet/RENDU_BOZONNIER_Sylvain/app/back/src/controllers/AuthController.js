// BOZONNIER Sylvain - CyberA 2028
class AuthController {
  login(query, body) {
    const { login, password } = body;
    if (login === 'admin' && password === 'password') {
      return { success: true };
    }
    return { success: false };
  }
}

module.exports = new AuthController();
