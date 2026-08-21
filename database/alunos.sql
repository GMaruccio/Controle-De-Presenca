-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 21/08/2026 às 20:21
-- Versão do servidor: 10.4.32-MariaDB
-- Versão do PHP: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `controle_presenca`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `alunos`
--

CREATE TABLE `alunos` (
  `id` int(11) NOT NULL,
  `ra` varchar(20) NOT NULL,
  `nome` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Despejando dados para a tabela `alunos`
--

INSERT INTO `alunos` (`id`, `ra`, `nome`) VALUES
(1, '123456789', 'João Silva'),
(2, '987654321', 'Maria Santos'),
(3, '111222333', 'Carlos Oliveira'),
(4, '444555666', 'Ana Souza'),
(5, '111222334', 'Cauã Silva'),
(6, '111222335', 'Jovas Oliveira'),
(7, '111222336', 'Felipe Costa'),
(8, '111222337', 'Luís Pereira'),
(9, '111222338', 'Gabriel Santos'),
(10, '111222339', 'Andreus Almeida'),
(11, '111222340', 'Mariana Rocha'),
(12, '111222341', 'Lucas Ferreira'),
(13, '111222342', 'Beatriz Souza'),
(14, '111222343', 'Rafael Rodrigues'),
(15, '111222344', 'Amanda Lima'),
(16, '111222345', 'Thiago Gomes'),
(17, '111222346', 'Juliana Martins'),
(18, '111222347', 'Pedro Barbosa'),
(19, '111222348', 'Carolina Ribeiro'),
(20, '111222349', 'Matheus Alves'),
(21, '111222350', 'Fernanda Carvalho'),
(22, '111222351', 'Diego Mendes'),
(23, '111222352', 'Camila Castro');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `alunos`
--
ALTER TABLE `alunos`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `ra` (`ra`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `alunos`
--
ALTER TABLE `alunos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
